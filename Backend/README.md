# Backend
### Tools:
[gradle](gradle.org)

In Eclipse import as Gradle project, you need Gradle plugin.

In Eclipse it needs lombok installation. It still builds without that, but Eclipse shows some errors - please visit [lombok project](https://projectlombok.org/) for more details.

### Build:

`gradle clean build`

### Deploy:

`java -jar build/libs/vrpBackend.jar`
