package com.vrp.vrpBackend.dao;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

import com.vrp.vrpBackend.controller.dto.Nodes;

@Repository
public interface NodesDao extends MongoRepository<Nodes,String>{

}
