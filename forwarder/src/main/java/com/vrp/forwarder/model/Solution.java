package com.vrp.forwarder.model;

import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.ArrayList;
import java.util.Comparator;
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

    public void sortCycles(Problem problem){
        cycles.forEach(c->c.countAngleToDepot(problem));
        cycles.sort(Comparator.comparing(Cycle::getAngleToDepot));
    }

    public List<Cycle> getRandomSeries(){
        List<Cycle> choosenCycles = new ArrayList<>();
        int totalCycles = cycles.size();
        int firstCycle = (int)(Math.random()*totalCycles);
        int nodeCount = 0;
        do {
            nodeCount += cycles.get(firstCycle%totalCycles).getNodes().length -1;
            choosenCycles.add(cycles.get(firstCycle%totalCycles));
            firstCycle++;
        }while (nodeCount<18);

        return choosenCycles;
    }
}
