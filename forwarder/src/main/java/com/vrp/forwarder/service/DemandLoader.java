package com.vrp.forwarder.service;

import com.vrp.forwarder.divider.Divider;
import com.vrp.forwarder.model.ProblemContainer;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;

@Service
@RequiredArgsConstructor
public class DemandLoader {

    private static LocalDateTime start;
    private final CitiesReader citiesReader;
    private final Divider divider;
/*
    public ProblemContainer updateDemands(){

    }
*/
    private void loadDemands(ProblemContainer problemContainer){
        //from database but now mocked
        if (start==null){
            start = LocalDateTime.now();
        }

    }
}
