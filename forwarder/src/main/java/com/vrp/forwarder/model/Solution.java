package com.vrp.forwarder.model;

import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.List;

@Data
@NoArgsConstructor
public class Solution {
    int demand;
    int distance;
    List<Cycle> cycles;

    public Solution(List<Solution> solutions){
        cycles = new ArrayList<>();
        solutions.forEach(s->{
            demand += s.getDemand();
            distance += s.getDistance();
            cycles.addAll(s.getCycles());
        });
    }
}
