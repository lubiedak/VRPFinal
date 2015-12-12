# Front End ReadMe
> A guide to setting up and developing the front-end component of BookIt V2

Node.js is a Javascript Platform for server-side programming, it allows the front-end to run on network and as such provides a realistic environment to test and develop. Node Package Manager or NPM is Node's package manager, which can be utilised for Anuglar, Ember, Javascript and a variety of other front-end tools. It provides a means to utilise packages such as Browserify, Grunt, Gulp and Bower, which will be explained later in the ReadMe.

To install Node.js and Node Package Manager (NPM):

1. Open a Terminal
2. Run :

```
$ sudo apt-get update
```
```
$ sudo apt-get install nodejs
```
```
$ sudo apt-get install npm
```

We need to create a symbolic link as most tools that utilise `nodejs` refer to it as `node`

```
$ sudo ln -s /usr/bin/nodejs /usr/bin/node
```

Check we have installed correctly by checking versions:

```
$ npm -v
$ node -v
```

Now we can use NPM to install packages

## Install Grunt globally
Grunt is a task runner for JavaScript and allows the automation of tasks and processes. To achieve this, Grunt utilises a GruntFile.js in the project folder which details the relevant task for the project. For BookIt 2.0 the WebUI is run on a local server utilising `grunt-connect`

In order to use grunt we need to install `grunt-cli` globally.

Open a terminal and run:

```
$ sudo npm install -g grunt-cli
$ grunt -version
```

## Pull down required node packages
In order to build the project we need to have the requried node dependencies and grunt tasks. Navigate to the root folder of the front-end project, this folder contains the two key files to needed to build and run the front-end project:

1. package.json - Which contains the node dependencies the project requires
2. Gruntfile.js - Where the runnable grunt tasks are defined

Open a terminal in this directory and run:
```
$ npm install
```

This will pull down all the required packages and place them in a folder called `node_modules`. If you have permissions errors or require sudo to install the local modules node or npm is not installed correctly.

## Running Grunt Tasks
In the `Gruntfile.js` several tasks are defined which can be run

### Grunt connect

Grunt connect is a simple server used to serve up the html and JavaScript for the front-end. To run the server simply open a terminal in the root of the front-end project (folder contains the Gruntfile.js and package.json)

```
$ grunt connect
```

This starts a server at `http://localhost:1333` where the project can be accessed.

The front-end server should now be running successfully!

### Grunt watch
Grunt watch monitors any changes to the scss stylesheets and if a change is noticed it compiles it to standard css. As with grunt connect open a terminal in the root of the front-end project and run:

```
$ grunt watch
```

## Finally

Now that the front-end is up and running, navigate to the Backend folder in the project folder and run

```
$ gradle clean build
```
```
$ java -jar build/libs/bookit.jar
```
