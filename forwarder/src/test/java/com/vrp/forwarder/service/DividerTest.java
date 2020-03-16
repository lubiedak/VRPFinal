package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Criteria;
import com.vrp.forwarder.model.GeneratorCfg;
import com.vrp.forwarder.model.Node;
import com.vrp.forwarder.model.Problem;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;


class DividerTest {

    private final Divider divider = new Divider();

    private final NodesGenerator nodesGenerator = new NodesGenerator();


    @Test
    void divide80ShouldReturnEqualGroups() {
        GeneratorCfg cfg = new GeneratorCfg(81, 0, 500,
                                                           1000, 1000, "", "", false);

        List<Node> nodes = nodesGenerator.generateNodes(cfg);
        Problem problem = Problem.builder().depot(new Node("Depot")).criteria(new Criteria()).nodes(nodes).build();

        List<Problem> problems = divider.divide(problem);

        assertThat(problems.size()).isEqualTo(5);
        int expectedSize = problems.get(0).getNodes().size();
        problems.forEach(p->assertThat(p.getNodes().size()).isEqualTo(expectedSize));
    }

    @Test
    void divide85ShouldReturnEqualGroups() {
        GeneratorCfg cfg = new GeneratorCfg(86, 0, 500,
                                            1000, 1000, "", "", false);

        List<Node> nodes = nodesGenerator.generateNodes(cfg);
        Problem problem = Problem.builder().depot(new Node("Depot")).criteria(new Criteria()).nodes(nodes).build();

        List<Problem> problems = divider.divide(problem);

        assertThat(problems.size()).isEqualTo(5);
        int expectedSize = problems.get(0).getNodes().size();
        problems.forEach(p->assertThat(p.getNodes().size()).isEqualTo(expectedSize));
    }

    @Test
    void divide84ShouldReturn5GroupsSimilarSize() {
        GeneratorCfg cfg = new GeneratorCfg(85, 0, 500,
                                            1000, 1000, "", "", false);

        List<Node> nodes = nodesGenerator.generateNodes(cfg);
        Problem problem = Problem.builder().depot(new Node("Depot")).criteria(new Criteria()).nodes(nodes).build();

        List<Problem> problems = divider.divide(problem);

        assertThat(problems.size()).isEqualTo(5);
        int expectedSize = problems.get(0).getNodes().size();
        problems.forEach(p->assertThat(p.getNodes().size())
                .isGreaterThanOrEqualTo(expectedSize).isLessThanOrEqualTo(expectedSize+1));
    }
}
