/* type item = {
     name: option(string),
     age: option(int),
     id: option(string),
   };

   module Decode = {
     let parseItemJson = json : item =>
       Json.Decode.{
         name: json |> optional(field("name", string)),
         age: json |> optional(field("age", int)),
         id: json |> optional(field("id", string)),
       };

     let parseItemsResponseJson = json =>
       Json.Decode.field("items", Json.Decode.array(parseItemJson), json);
   }; */
/*
   let reposUrl = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";

 let fetchRepos = () =>
   Js.Promise.(
     Fetch.fetch(reposUrl)
     |> then_(Fetch.Response.text)
     |> then_(jsonText =>
          resolve(parseReposResponseJson(Js.Json.parseExn(jsonText)))
        )
   );
   */