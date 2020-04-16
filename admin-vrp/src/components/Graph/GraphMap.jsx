import React from 'react'
import Sigma, {NOverlap} from 'react-sigma';

const GraphMap = ({ data }) => {
    if(Object.keys(data).length>0){
    return (
        <Sigma graph={data} renderer="canvas" style={{width:"800px", height:"800px"}}>
        </Sigma>
    )
} else {
    return null;
}
};

export default GraphMap