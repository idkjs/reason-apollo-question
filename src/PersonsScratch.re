/* let ste = ReasonReact.string;

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

   let (|?>) = (fn, opt) =>
     switch (opt) {
     | None => None
     | Some(value) => fn(value)
     };

   let (|?>>) = (fn, opt) =>
     switch (opt) {
     | None => None
     | Some(value) => Some(fn(value))
     };

   let (|?) = (opt, default) =>
     switch (opt) {
     | None => default
     | Some(value) => value
     };

   /* let renderItemNode = node => {
        let name =
          switch (node##name) {
          | Some(name) => ReasonReact.string(name ++ {js|😭|js})
          | None => <li> (ReasonReact.string("No name")) </li>
          };
        let id =
          switch (node##id) {
          | Some(id) => ReasonReact.string(id ++ {js|😭|js})
          | None => <li> (ReasonReact.string("No id")) </li>
          };
        let age =
          switch (node##age) {
          | Some(age) => ReasonReact.string(string_of_int(age) ++ {js|😭|js})
          | None => <li> (ReasonReact.string("No id")) </li>
          };

        ReasonReact.array(name ++ age ++ id);
      }; */
   let renderName = node =>
     switch (node##name) {
     | Some(name) => ReasonReact.string(name ++ {js|😭|js})
     | None => <li> (ReasonReact.string("No name")) </li>
     };

   let renderId = node =>
     switch (node##id) {
     | Some(id) => ReasonReact.string(id ++ {js|😭|js})
     | None => <li> (ReasonReact.string("No id")) </li>
     };

   let renderAge = node =>
     switch (node##age) {
     | Some(age) => ReasonReact.string(string_of_int(age) ++ {js|😭|js})
     | None => <li> (ReasonReact.string("No id")) </li>
     };
   /*
      switch (item##name) {
      | None => <li> (ReasonReact.string("No name")) </li>
      | Some(name) => renderItem(name)
      },
      switch (item##id) {
      | None => <li> (ReasonReact.string("No id")) </li>
      | Some(id) => renderItem(id)
      },
      switch (item##age) {
      | None => <li> (ReasonReact.string("No age")) </li>
      | Some(age) => renderItem(string_of_int(age))
      },
    */
   let renderItem = item => ReasonReact.string(item##name ++ {js|🌟|js});

   let renderItemDetails = item =>
     <div>
       <h2> (item##name |? "No name" |> ReasonReact.string) </h2>
       <h3> (item##id |? "No Id" |> ReasonReact.string) </h3>
       <h3> (item##age |? "No age" |> ReasonReact.string) </h3>
     </div>;
   let renderPersonList = personList =>
     switch (personList) {
     | None => <div> (ReasonReact.string("No persons")) </div>
     | Some(list) =>
       switch (list##items) {
       | None => <div> (ReasonReact.string("No items")) </div>
       | Some(items) =>
         <ul>
           (
             ReasonReact.createDomElement(
               "div",
               ~props={"className": "whatever"},
               Array.map(
                 item =>
                   switch (item) {
                   | None => <li> (ReasonReact.string("No item")) </li>
                   | Some(item) =>
                     <li>
                       (
                         switch (item) {
                         | None => ReasonReact.string("No item")
                         | Some(item) => renderItemDetails(item)
                         }
                       )
                     </li>
                   },
                 items,
               ),
             )
           )
         </ul>
       }
     };
   let parseItems = listPeople =>
     switch (listPeople) {
     | Some(listPeople) =>
       let items = listPeople##items;
       switch (items) {
       | Some(items) =>
         let parsedItems =
           Array.map(
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
   /* let renderItemDetails = item =>
      <div>
        <h2> (item##name |? "No name" |> ReasonReact.string) </h2>
        <h2> (item##id |? "No id" |> ReasonReact.string) </h2>
        <h2> (item##age |? "No age" |> ReasonReact.string) </h2>
      </div>; */
   /* <h3> (item##id |> ReasonReact.string) </h3> */

   /* let listItems = (itemsData: option(array(ItemData.item))) =>
        switch (itemsData) {
        | Some(items) =>
          ReasonReact.array(
            Array.map(
              (item: ItemData.item) => <ListItem key=item.name item />,
              items,
            ),
          )
        | None => ReasonReact.string("Loading")
        };
      let parseList = ItemData.Decode.parseItemsResponseJson; */
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
                      let parsedItems = parseItems(listPeople);
                      Js.log(parsedItems);
                      <div> <h1> (ReasonReact.string("TEST")) </h1> </div>;
                    /* (renderPersonList(response##listPeople)) */
                    }
                  )
                </div>
                /* renderPersonList(response##listPeople##items) */
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
      }; */ */