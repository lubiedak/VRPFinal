package com.vrp.forwarder.model;

import com.vrp.forwarder.service.NodesGenerator;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;

class CycleTest {


    private final NodesGenerator nodesGenerator = new NodesGenerator();

    @Test
    void shouldFilterSpecifiedNodesFromCycle() {
        GeneratorCfg cfg = new GeneratorCfg(10, 0, 500);

        List<Node> nodes = nodesGenerator.generateNodes(cfg);

        Problem problem = Problem.builder().depot(new Node("Depot")).criteria(new Criteria()).nodes(nodes).build();

        int[] nodeIds = {0,2,3};
        Cycle cycle = new Cycle();
        cycle.setNodes(nodeIds);
        nodes = cycle.toNodes(problem);
        cycle.countAngleToDepot(problem);

        assertThat(nodes.size()).isEqualTo(3);
        assertThat(nodes.get(1).getId()).isEqualTo(2);
    }
}
