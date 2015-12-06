$(document).ready(function() {
$("#register").click(function() {

var nodes_Count = $("#nodes_Count").val();
var min_Demand = $("#min_Demand").val();
var max_Demand = $("#max_Demand").val();
var max_X = $("#max_X").val();
var max_Y = $("#max_Y").val();
if (nodes_Count == '' || min_Demand == '' || max_Demand == '' || max_X == '' || max_Y == '') {
alert("Please fill all fields...!!!!!!");
} else {
$.post("http://127.0.0.1:8080/rest/node/generate", {
nodesCount: nodes_Count,
minDemand: min_Demand,
maxDemand: max_Demand,
maxX : max_X,
maxY : max_Y
}, function(data) {
if (data == 'You have Successfully Registered.....') {
$("form")[0].reset();
}
alert(data);
});
}
});
});
