const express = require("express");
const bodyParser = require("body-parser");
const { graphqlExpress, graphiqlExpress } = require("apollo-server-express");
const { makeExecutableSchema } = require("graphql-tools");

// Some fake data
const items = [
  {
    age: 23,
    id: "123",
    name: "BobTest"
  },
  {
    age: 24,
    id: "124",
    name: "JoeTest"
  },
  {
    age: 25,
    id: "125",
    name: "JimTest"
  }
];

// The GraphQL schema in string form
const typeDefs = `
    type Person implements Node {
        age: Int!
        id: ID!
        name: String!
    }

    type PersonConnection {
        items: [Person]
        nextToken: String
    }

    type Query {
        getPerson(id: ID!): Person
        listPeople(after: String, first: Int): PersonConnection
        person(id: ID!): Person
    }
`;

// The resolvers
const resolvers = {
  Query: { listPeople: () => listPeople }
};

// Put together a schema
const schema = makeExecutableSchema({
  typeDefs,
  resolvers
});

// Initialize the app
const app = express();

// The GraphQL endpoint
app.use("/graphql", bodyParser.json(), graphqlExpress({ schema }));

// GraphiQL, a visual editor for queries
app.use("/graphiql", graphiqlExpress({ endpointURL: "/graphql" }));

// Start the server
app.listen(3000, () => {
  console.log("Go to http://localhost:3000/graphiql to run queries!");
});
