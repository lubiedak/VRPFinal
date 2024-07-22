package main

import (
	"fmt"
	"net/http"
	"strconv"

	"github.com/gin-contrib/cors"
	"github.com/gin-gonic/gin"
)

func main() {
    router := gin.Default()
    router.Use(cors.New(cors.Config{
        AllowOrigins: []string{"*"},
        AllowMethods: []string{"GET", "PUT", "PATCH", "DELETE"},
        AllowHeaders: []string{"Content-Type,access-control-allow-origin, access-control-allow-headers"},
    }))
    
    router.GET("/example/random/:size", randomExample)
    create(5, 3, createNodes(12, 500))
    initPerms(5)

    fmt.Println("Tu")

    for row := 0; row < 24; row++ {
        for column := 0; column < 4; column++{
            fmt.Print(perms[4][row][column], " ")
        }
        fmt.Print("\n")
    } 

    //router.GET("/example/:id", exampleById)
    //router.POST("/generate", generateExample)

    router.Run("localhost:8081")
}

func randomExample(c *gin.Context) {
    size, _ := strconv.Atoi(c.Param("size"))
    c.IndentedJSON(http.StatusOK, randExample(size))
}