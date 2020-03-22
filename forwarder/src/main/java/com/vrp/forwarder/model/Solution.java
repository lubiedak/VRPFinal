package com.vrp.forwarder.model;

import lombok.Data;

import java.util.List;

@Data
public class Solution {
    int demand;
    int distance;
    List<Cycle> cycles;
}
