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

let renderItemNode = node => {
  switch (node##name) {
  | Some(name) => ReasonReact.string(name ++ {js|😭|js})
  | None => <li> (ReasonReact.string("No name")) </li>
  };
  switch (node##id) {
  | Some(id) => ReasonReact.string(id ++ {js|😭|js})
  | None => <li> (ReasonReact.string("No id")) </li>
  };
  switch (node##age) {
  | Some(age) => ReasonReact.string(string_of_int(age) ++ {js|😭|js})
  | None => <li> (ReasonReact.string("No id")) </li>
  };
};

/* let renderPersonList = items : array(ItemData.item) =>
   switch (items) {
   | None =>
     ReasonReact.array(item, ReasonReact.string("No repository items"))
   | Some(items) =>
     <ul>
       (
         ReasonReact.createDomElement(
           "div",
           ~props={"className": "whatever"},
           Array.map(
             item => {
               let id = item##id |> fromOption;
               let age = optional(item##age);
               let name = optional(item##name);
               switch (item) {
               | None => <li> (ReasonReact.string("No item")) </li>
               | Some(item) =>
                 <li>
                   (
                     switch (item) {
                     | None => ReasonReact.string("No item")
                     | Some(item) => renderItemNode(item)
                     }
                   )
                 </li>
               };
             },
             items,
           ),
         )
       )
     </ul>
   }; */
/* let renderItemDetails = item =>
   <div>
     <h2> (item##name |? "No name" |> ReasonReact.string) </h2>
     <h2> (item##id |? "No id" |> ReasonReact.string) </h2>
     <h2> (item##age |? "No age" |> ReasonReact.string) </h2>
   </div>; */
/* <h3> (item##id |> ReasonReact.string) </h3> */
let component = ReasonReact.statelessComponent("Query");

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
                   <div> (ReasonReact.string("TEST")) </div>;
                 }
               )
             </div>
             /* renderPersonList(response##listPeople##items) */
         )
    </GetAllPersonsQuery>,
};