package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Problem;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

@Service
public class Divider {

    private final static int BASE_GROUP_SIZE = 16;

    public List<Problem> divide(Problem p){
        p.sortNodes();
        int totalSize = p.getNodes().size();
        int nOfGroups = totalSize/BASE_GROUP_SIZE;
        float averageGroupSize = (totalSize+0.0f)/nOfGroups;
        List<Problem> problems = new ArrayList<>();
        int i;
        for(i = 0; i<nOfGroups-1; i++){
            System.out.println((int)(i*averageGroupSize));
            System.out.println((int)((i+1)*averageGroupSize));
            problems.add(Problem.builder().criteria(p.getCriteria()).depot(p.getDepot())
                                .nodes(p.getNodes().subList((int)(i*averageGroupSize), (int)((i+1)*averageGroupSize))).build());
        }

        System.out.println((int)(i*averageGroupSize));
        System.out.println(totalSize);
        problems.add(Problem.builder().criteria(p.getCriteria()).depot(p.getDepot())
                            .nodes(p.getNodes().subList((int)(i*averageGroupSize), totalSize)).build());

        return problems;
    }
}
