// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var ApolloProvider = require("reason-apollo/src/ApolloProvider.bs.js");
var Page$ReactTemplate = require("./Page.bs.js");
var Client$ReactTemplate = require("./Client.bs.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, ApolloProvider.make(Client$ReactTemplate.client, /* array */[ReasonReact.element(/* None */0, /* None */0, Page$ReactTemplate.make(/* array */[]))])), "index");

/*  Not a pure module */
