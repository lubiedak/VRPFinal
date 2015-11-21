package com.vrp.vrpBackend.controller.dto;

import org.springframework.hateoas.ResourceSupport;

import com.fasterxml.jackson.annotation.JsonCreator;
import com.fasterxml.jackson.annotation.JsonProperty;

public class GenericResponse extends ResourceSupport {

    private final String content;

    @JsonCreator
    public GenericResponse(@JsonProperty("content") String content) {
        this.content = content;
    }

    public String getContent() {
        return content;
    }
}