import React from 'react'
import Sigma, {NOverlap} from 'react-sigma';

const GraphMap = ({ data }) => {
    return (
        <Sigma graph={data} renderer="canvas" style={{width:"400px", height:"400px"}}>
            <NOverlap gridSize={10} maxIterations={100}/>
        </Sigma>
    )
};

export default GraphMap