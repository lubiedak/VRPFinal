# Backend
### Tools:
[gradle](gradle.org)

In Eclipse import as Gradle project, you need some Gradle plugin.

In Eclipse it needs some lombok installation. It still builds without that, but Eclipse shows some errors if you don't run these steps - please visit [lombok project](https://projectlombok.org/)

### Build:

`gradle clean build`

### Deploy:

`java -jar build/libs/vrpBackend.jar`
