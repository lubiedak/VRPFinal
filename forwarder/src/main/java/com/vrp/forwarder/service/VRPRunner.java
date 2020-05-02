package com.vrp.forwarder.service;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.vrp.forwarder.model.Problem;
import com.vrp.forwarder.model.Solution;
import lombok.Data;
import lombok.RequiredArgsConstructor;
import lombok.Setter;
import lombok.extern.slf4j.Slf4j;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;


@Service
@ConfigurationProperties(prefix = "vrprunner")
@Slf4j
@RequiredArgsConstructor
public class VRPRunner {
    private final RestTemplate restTemplate;
    private final ObjectMapper objectMapper;
    @Setter
    private String url;
    @Setter
    private String urlCities;

    public Solution runStandard(final Problem p) {
        final HttpEntity<String> request = prepareRequest(p);

        final ResponseEntity<Solution> response = restTemplate.postForEntity(url, request, Solution.class);

        return response.getBody();
    }


    public Solution runForCities(final Problem p) {
        final HttpEntity<String> request = prepareRequest(p);

        final ResponseEntity<Solution> response = restTemplate.postForEntity(urlCities, request, Solution.class);

        return response.getBody();
    }

    private HttpEntity<String> prepareRequest(final Problem p) {
        final HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_JSON);

        HttpEntity<String> request = null;
        try {
            request = new HttpEntity<>(objectMapper.writeValueAsString(p), headers);
            log.info(request.toString());
        } catch (final JsonProcessingException e) {
            e.printStackTrace();
        }
        return request;
    }
}
