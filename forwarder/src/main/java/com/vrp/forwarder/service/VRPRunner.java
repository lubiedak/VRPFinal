package com.vrp.forwarder.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.vrp.forwarder.model.Problem;
import lombok.Data;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;


@Service
@Data
@ConfigurationProperties(prefix = "vrprunner")
@Slf4j
@RequiredArgsConstructor
public class VRPRunner {
    private final RestTemplate restTemplate;
    private final ObjectMapper objectMapper;

    public String run(Problem p) throws JsonProcessingException {
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);


        HttpEntity<String> request = new HttpEntity<>(objectMapper.writeValueAsString(p), headers);
        log.info(request.toString());

        ResponseEntity<String> response = restTemplate
                .postForEntity("http://localhost:18080/problem/solve", request , String.class );

        return response.getBody();
    }
}
