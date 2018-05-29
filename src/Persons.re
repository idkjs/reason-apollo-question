let ste = ReasonReact.string;

module GetAllPersons = [%graphql
  {|
    query getAllPersons {
      listPeople {
        items {
          age
          id
          name
        }
      }
    }
  |}
];

module GetAllPersonsQuery = ReasonApollo.CreateQuery(GetAllPersons);
let component = ReasonReact.statelessComponent("Query");

let parseItems = listPeople =>
  switch (listPeople) {
  | Some(listPeople) =>
    let items = listPeople##items;
    switch (items) {
    | Some(items) =>
      let parsedItems =
        Js.Array.map(
          item =>
            switch (item) {
            | Some(item) =>
              let name = item##name;
              let id = item##id;
              let age = item##age;
              switch (name, id, age) {
              | (Some(name), Some(id), Some(age)) =>
                id ++ " - " ++ name ++ " -- " ++ string_of_int(age)
              | (Some(name), None, None) => name
              | (None, Some(id), None) => id
              | (None, None, Some(age)) => string_of_int(age)
              | (None, None, None) => "Error retrieving item"
              };
            | None => "Error retrieving item"
            },
          items,
        );
      parsedItems;
    | None => [||]
    };
  | None => [||]
  };

let make = _children => {
  ...component,
  render: _self =>
    <GetAllPersonsQuery>
      ...(
           ({result}) =>
             <div>
               <h1> ("Persons: " |> ste) </h1>
               (
                 switch (result) {
                 | Error(e) =>
                   Js.log(e);
                   "Something Went Wrong" |> ste;
                 | Loading => "Loading" |> ste
                 | Data(response) =>
                   Js.log(response##listPeople);
                   let listPeople = response##listPeople;
                   let items = response##listPeople##items;
                   Js.log(items);

                   /* let parsedItems = parseItems(listPeople);
                      Js.log(parsedItems); */
                   <div> <h1> (ReasonReact.string("TEST")) </h1> </div>;
                 }
               )
             </div>
         )
    </GetAllPersonsQuery>,
};
/* compiles, nothing in ui */
/* let make = _children => {
     ...component,
     render: _self =>
       <GetAllPersonsQuery>
         ...(
              ({result}) =>
                <div>
                  <h1> ("Persons: " |> ste) </h1>
                  (
                    switch (result) {
                    | Error(e) =>
                      Js.log(e);
                      "Something Went Wrong" |> ste;
                    | Loading => "Loading" |> ste
                    | Data(response) =>
                      Js.log(response##listPeople);
                      <div> (ReasonReact.string("TEST")) </div>;
                    }
                  )
                </div>
                /* renderPersonList(response##listPeople##items) */
            )
       </GetAllPersonsQuery>,
   }; */