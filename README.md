# Reason-Apollo Swapi

This project illustrates the usage of reason-apollo to query the [SWAPI](http://swapi.apis.guru/) and serves as an example on how to use the project.

## Getting started

```
npm install
npm start
# in another tab
npm run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up the nested html files in `src/*` (**no server needed!**). Then modify whichever file in `src` and refresh the page to see the changes.

## [get-introspection-schema](https://docs.aws.amazon.com/ja_jp/cli/latest/reference/appsync/get-introspection-schema.html)

run: `aws appsync get-introspection-schema --api-id pdtqkhbx3nawtfg5lody6w6jcu --format JSON graphql_schema.json`

yarn send-introspection-query https://h25cvu6lonfilcrryg7xo5fjne.appsync-api.eu-west-1.amazonaws.com/graphql --headers 'Authorization: bearer da2-2ajoq2qmsvgspdw6hljfdj2lb4'

## decoding

error:

```s
This has type:
  option({. "items": option(Js.Array.t(option({. "age": int, "id":
                                                string, "name": string})))})
But somewhere wanted:
  Js.t('a)
option({_.. "items": option(Js.Array.t(option({_.. "age": option(string),
                                                "id": option(string),
                                                "name": option(string)})))})
```

cleanedup:

```.re
option({
    .
    "items": option(
        Js.Array.t(
            option(
                {
                .
                "age": int,
                "id":string,
                "name": string
                }
            )
        )
    )
})
```
