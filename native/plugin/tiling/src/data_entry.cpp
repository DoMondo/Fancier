#include <fancier/plugin/tiling/data_entry.h>

#include <sys/types.h>
#include <unistd.h>
#include <fancier/utils.h>

#define IO_BUFFER_SZ (4 * 1024) // 4K


int writeEntry (int fd, size_t idx, bool isNewEntry, const void* entry, size_t entrySz) {
  // If sizeof(DataHeader) + (idx * entrySz) exceeds the size of the file, the new data is appended
  // If not, it is replaced at the right spot
  // isNewEntry is used when inserting at the middle of the file. It ensures that no data is replaced
  off_t fileSize = lseek(fd, 0, SEEK_END);
  off_t entryPos = lseek(fd, sizeof(DataHeader) + idx * entrySz, SEEK_SET);

  if (fileSize < 0 || entryPos < 0)
    return -1;

  char buffer[IO_BUFFER_SZ];

  if (isNewEntry && fileSize > entryPos) {
    // Move all following entries towards the end of the file before inserting the new one
    off_t currentEntryOffset = lseek(fd, -entrySz, SEEK_END);

    while (currentEntryOffset >= entryPos) {
      if (fcUtils_readFileData(fd, (char*) buffer, entrySz) < 0)
        return -1;

      if (fcUtils_writeFileData(fd, (char*) buffer, entrySz) < 0)
        return -1;

      currentEntryOffset = lseek(fd, -3 * entrySz, SEEK_CUR);
    }

    if (currentEntryOffset < 0)
      return -1;

    // Resposition to the place where the new entry has to be written
    if (lseek(fd, entryPos, SEEK_SET) < 0)
      return -1;
  }

  // Insert the new entry at its position
  if (fcUtils_writeFileData(fd, (char*) entry, entrySz) < 0)
    return -1;

  return fdatasync(fd);
}
