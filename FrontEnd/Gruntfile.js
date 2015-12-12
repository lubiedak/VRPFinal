
var path = {
  ROOT_PATH: './',
  SCRIPTS: './dest',
  CSS: './css'
}

module.exports = function(grunt) {

  // Project configuration.
  grunt.initConfig({

    pkg: grunt.file.readJSON('package.json'),
    
    

    connect: {
      example: {
        port: 1333,
        base: path.ROOT_PATH
      }
    },

    compass: {
      dist: {
        options: {
          cssDir: path.CSS,
          environment: 'production'
        }
      },
      dev: {
        options: {
          cssDir: path.CSS,
          environment: 'development'
        }
      }
    },

    watch: {
      scripts: {
        tasks: ['compass:dev'],
        options: {
          spawn: false,
        },
      },
    },
     
    htmlmin: {                                     
      dist: {                                      
        options: {                                 
          removeComments: true,
          collapseWhitespace: true
        },
        files: {                         
          'index.html': 'index-dist.html'  // 'destination': 'source'     
        }
      }
    }
  });

  

  

  

  // Load the plugin that provides the "uglify" task.
  grunt.loadNpmTasks('grunt-connect');

      /** Load the package that provides the compass task */
  grunt.loadNpmTasks('grunt-contrib-compass');

  /** Load the package for the shell task */
  grunt.loadNpmTasks('grunt-shell');

  /** Load the package for the Uglify task */
  grunt.loadNpmTasks('grunt-contrib-uglify');

  /** Load the package for the Watch task */
  grunt.loadNpmTasks('grunt-contrib-watch');

  /** Register The Verison Increment Task */
  grunt.registerTask('bumpVersion', ['shell']);

  grunt.registerTask('build', ['shell:build']);

  grunt.registerTask('apt', ['shell:apt']);



  // Default task(s).
  grunt.registerTask('build', [
    "compass",
    "cssmin",
    "copy:main",
    "concat",
  ]);
  

  grunt.registerTask('bd', [

  ]);

  // Default task(s).
  grunt.registerTask('default', [
    'compass:dist',
  ]);



  

};
