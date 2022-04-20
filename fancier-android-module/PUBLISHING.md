# Publishing the module for Android
The android project located in this directory uses the sources from `native` and `java` directories and bundles them in an AAR module. For this, first make sure that you have generated the code, following the main README.md, in the section called "Code Generation".

## Defining the version id 
Edit the `gradle.properties` file and modify the `version` setting.

## Testing the module
The app directory contains an application that tests the built module from the repository `mavenLocal`. In order to build and publish it, execute:
```bash
./gradlew :fancier:publishToMavenLocal
```
Once it is done, you can check that the module exists in the local maven repository:
```bash
$ ls -la ~/.m2/repository/es/ull/pcg/hpc/fancier
total 16
drwxr-xr-x 3 ogomez ogomez 4096 Mar 28 16:46 .
drwxr-xr-x 3 ogomez ogomez 4096 Mar 28 16:46 ..
drwxr-xr-x 2 ogomez ogomez 4096 Mar 28 16:46 0.0.1-SNAPSHOT
-rw-r--r-- 1 ogomez ogomez  317 Mar 28 16:46 maven-metadata-local.xml
```
Now, uncomment the dependency in the `build.gradle` of the `app`:

```groovy
dependencies {
    ...
    implementation "com.github.DoMondo:Fancier:${version}"
}
```
Now you should be able to use it in the application.

## Publishing to Jitpack

Once the version id has been defined and the candidate module has been tested, you can publish it automatically to JitPack. For this, create a tag with the version and a release on GitHub for this tag. When this version is requested from another app, it will be automatically compiled and packaged in JitPack. You can check the log and the package status in  [https://jitpack.io/#DoMondo/Fancier](https://jitpack.io/#DoMondo/Fancier).