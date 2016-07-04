package com.vrp.vrpBackend.divider;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import com.vrp.vrpBackend.model.Node;

public class NodeClassifierTest {

	NodeClassifier classifier;

	@Before
	public void setup() {
		Node base = new Node("base");
		base.setX(0);
		base.setY(0);
		classifier = new NodeClassifier(base);
	}

	@Test
	public void test1Quarter() {
		Node n = createNode(1, 1);
		double actual = classifier.classify(n);
		Assert.assertEquals(45.0, actual, 0.001);
	}

	@Test
	public void test2Quarter() {
		Node n = createNode(-1, 1);
		double actual = classifier.classify(n);
		Assert.assertEquals(135.0, actual, 0.001);
	}

	@Test
	public void test3Quarter() {
		Node n = createNode(-1, -1);
		double actual = classifier.classify(n);
		Assert.assertEquals(225.0, actual, 0.001);
	}

	@Test
	public void test4Quarter() {
		Node n = createNode(1, -1);
		double actual = classifier.classify(n);
		Assert.assertEquals(315.0, actual, 0.001);
	}

	private Node createNode(int x, int y) {
		Node n = new Node("N");
		n.setX(x);
		n.setY(y);
		return n;
	}
}
