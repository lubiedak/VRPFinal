/*!

=========================================================
* VRP - v1.3.0
=========================================================

* Product Page: https://www.creative-tim.com/product/light-bootstrap-dashboard-react
* Copyright 2019 Creative Tim (https://www.creative-tim.com)
* Licensed under MIT (https://github.com/creativetimofficial/light-bootstrap-dashboard-react/blob/master/LICENSE.md)

* Coded by Creative Tim

=========================================================

* The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

*/
import React, { Component } from "react";
import {
  Grid,
  Row,
  Col,
  FormGroup,
  ControlLabel,
  FormControl
} from "react-bootstrap";

import { Card } from "components/Card/Card.jsx";
import { FormInputs } from "components/FormInputs/FormInputs.jsx";
import { UserCard } from "components/UserCard/UserCard.jsx";
import Button from "components/CustomButton/CustomButton.jsx";

import avatar from "assets/img/faces/face-3.jpg";

class ControlPanel extends Component {
  render() {
    return (
      <div className="content">
        <Grid fluid>
          <Row>
            <Col md={4}>
              <Card
                title="Config & Optimizations"
                content={
                  <form>
                    <FormInputs
                      ncols={["col-md-4", "col-md-4"]}
                      properties={[
                        {
                          label: "Optimize execution",
                          placeholder: "optimize",
                          type: "checkbox",
                        },
                        {
                          label: "Save trucks",
                          placeholder: "saveTrucks",
                          type: "checkbox",
                        },
                      ]}
                    />
                </form>
                }
              />
            </Col>
            <Col md={3}>
            <Card
                title="Depots"
                content={
                  <form>
                    <FormInputs
                      ncols={["col-md-3", "col-md-3", "col-md-3"]}
                      properties={[
                        {
                          label: "Złotów",
                          type: "checkbox",
                        },
                        {
                          label: "Łódź",
                          type: "checkbox",
                        },
                        {
                          label: "Wrocław",
                          type: "checkbox",
                        }
                      ]}
                    />
                  </form>
                }
              />
            </Col>
          </Row>
        </Grid>
      </div>
    );
  }
}

export default ControlPanel;
