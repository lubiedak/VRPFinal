package com.vrp.vrpBackend.dao;

import org.springframework.data.mongodb.repository.MongoRepository;
import com.vrp.vrpBackend.controller.dto.Nodes;

public interface NodesDao extends MongoRepository<Nodes,String>{

}
