package com.vrp.forwarder.service;

import com.vrp.forwarder.model.Cycle;
import com.vrp.forwarder.model.Node;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

@Slf4j
@Service
public class CycleService {

    public Cycle generateRandom(int n, int maxN) {
        int size = n < maxN ? n : maxN;
        Cycle c = new Cycle();
        List<Node> nodes = new ArrayList<>(size);
        Random r = new Random();
        for(int i = 0; i<size; ++i){
            Node node = new Node(""+i);
            node.setId(r.nextInt(maxN));
            nodes.add(node);
        }
        c.setNodes(nodes);
        return c;
    }
}
