import React, {Component} from 'react';
import GraphMap from './GraphMap';

class GraphFetcher extends Component {
    render() {
        return (
            <GraphMap data={this.state.nodes} />
        )
    }

    state = {
        nodes: []
    };

    componentDidMount() {
        fetch('/api/v1/city/solve/1?draw=true', {
            method: 'POST'})
            .then(res => res.json())
            .then((data) => {
                this.setState({ nodes: data })
            })
            .catch(console.log)
    }
}

export default GraphFetcher;