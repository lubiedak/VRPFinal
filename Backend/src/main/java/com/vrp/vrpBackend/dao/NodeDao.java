package com.vrp.vrpBackend.dao;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

import com.vrp.vrpBackend.model.Node;

@Repository
public interface NodeDao extends MongoRepository<Node,String>{

}
