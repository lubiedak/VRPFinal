package com.vrp.forwarder.service;

import com.vrp.forwarder.divider.Divider;
import com.vrp.forwarder.model.GeneratorCfg;
import com.vrp.forwarder.model.Problem;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.assertj.core.api.Assertions.assertThat;


class DividerTest {

    private final Divider divider = new Divider();

    private final ProblemGenerator problemGenerator = new ProblemGenerator();
    private final int MAX_GROUP_SIZE = 20;
    private final int MIN_GROUP_SIZE = 10;


    @Test
    void divide80ShouldReturn4EqualGroups() {
        GeneratorCfg cfg = new GeneratorCfg(80, 0, 500);

        Problem problem = problemGenerator.generate(cfg);

        List<Problem> problems = divider.divide(problem, 20);

        assertThat(problems.size()).isEqualTo(4);
        problems.forEach(p->assertThat(p.getNodes().size()).isEqualTo(MAX_GROUP_SIZE));
    }

    @Test
    void divide85ShouldReturnEqualGroups() {
        GeneratorCfg cfg = new GeneratorCfg(85, 0, 500);
        Problem problem = problemGenerator.generate(cfg);

        List<Problem> problems = divider.divide(problem, 20);

        assertThat(problems.size()).isEqualTo(5);
        problems.forEach(p->assertThat(p.getNodes().size()).isEqualTo(17));
    }

    @Test
    void divide84ShouldReturn5GroupsSimilarSize() {
        GeneratorCfg cfg = new GeneratorCfg(84, 0, 500);
        Problem problem = problemGenerator.generate(cfg);

        List<Problem> problems = divider.divide(problem, 20);

        assertThat(problems.size()).isEqualTo(5);
        int expectedSize = 16;
        problems.forEach(p->assertThat(p.getNodes().size())
                .isGreaterThanOrEqualTo(expectedSize).isLessThanOrEqualTo(expectedSize+1));
    }

    @Test
    void divide20ShouldReturn1Group() {
        GeneratorCfg cfg = new GeneratorCfg(20, 0, 500);
        Problem problem = problemGenerator.generate(cfg);

        List<Problem> problems = divider.divide(problem, 20);

        assertThat(problems.size()).isEqualTo(1);
        assertThat(problems.get(0).getNodes().size()).isEqualTo(MAX_GROUP_SIZE);
    }

    @Test
    void divide40ShouldReturn2GroupsSameSize() {
        GeneratorCfg cfg = new GeneratorCfg(40, 0, 500);
        Problem problem = problemGenerator.generate(cfg);

        List<Problem> problems = divider.divide(problem, 20);

        assertThat(problems.size()).isEqualTo(2);
        problems.forEach(p->assertThat(p.getNodes().size())
                .isEqualTo(MAX_GROUP_SIZE));
    }

    @Test
    void divide41ShouldReturn3GroupsSimilarSize() {
        GeneratorCfg cfg = new GeneratorCfg(41, 0, 500);
        Problem problem = problemGenerator.generate(cfg);

        List<Problem> problems = divider.divide(problem, 20);

        assertThat(problems.size()).isEqualTo(3);
        int expectedSize = 13;
        problems.forEach(p->assertThat(p.getNodes().size())
                .isGreaterThanOrEqualTo(expectedSize).isLessThanOrEqualTo(expectedSize+1));
    }

    @Test
    void divide39ShouldReturn2GroupsSimilarSize() {
        GeneratorCfg cfg = new GeneratorCfg(39, 0, 500);
        Problem problem = problemGenerator.generate(cfg);

        List<Problem> problems = divider.divide(problem, 20);

        assertThat(problems.size()).isEqualTo(2);
        int expectedSize = 19;
        problems.forEach(p->assertThat(p.getNodes().size())
                .isGreaterThanOrEqualTo(expectedSize).isLessThanOrEqualTo(expectedSize+1));
    }
}
