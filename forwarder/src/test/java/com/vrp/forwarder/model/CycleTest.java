package com.vrp.forwarder.model;

import com.vrp.forwarder.service.ProblemGenerator;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

class CycleTest {


    private final ProblemGenerator problemGenerator = new ProblemGenerator();

    @Test
    void shouldFilterSpecifiedNodesFromCycle() {
        GeneratorCfg cfg = new GeneratorCfg(10, 0, 500);

        Problem problem = problemGenerator.generate(cfg);

        int[] nodeIds = {0,2,3};
        Cycle cycle = new Cycle();
        cycle.setNodes(nodeIds);
        List<Node> nodes = cycle.toNodes(problem);
        cycle.countAngleToDepot(problem);

        assertThat(nodes.size()).isEqualTo(3);
        assertThat(nodes.get(1).getId()).isEqualTo(2);
    }
}
