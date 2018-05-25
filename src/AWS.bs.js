// Generated by BUCKLESCRIPT VERSION 3.1.4, PLEASE EDIT WITH CARE
'use strict';

var AwsAppsync = require("aws-appsync");
var Js_null_undefined = require("bs-platform/lib/js/js_null_undefined.js");

function createAWSAppSyncClient(url, region, auth, _) {
  return new AwsAppsync.AWSAppSyncClient({
              url: Js_null_undefined.fromOption(url),
              region: Js_null_undefined.fromOption(region),
              auth: Js_null_undefined.fromOption(auth)
            });
}

var AppSync = /* module */[/* createAWSAppSyncClient */createAWSAppSyncClient];

exports.AppSync = AppSync;
/* aws-appsync Not a pure module */
