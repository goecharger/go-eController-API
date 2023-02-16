[Deutsch](http-de.md) &bull; English

# HTTP Api

[The api keys](apikeys-en.md) can be read and written via the HTTP Api.

For that the HTTP API (v2) has to be enabled from the app:

<img src="screenshots/http-api-app-enable.png?raw=true" width="200" />

## Getting all values in one request
<small>hihger system load, lots of traffic, shouldn't be used for productive setups</small>

`http://192.168.0.99/api/status`

<img src="screenshots/http-api-status.png?raw=true" />

## Getting selective values
To reduce the system load the status request can be filtered so that only certain api keys are part of it.

`http://192.168.0.75/api/status?filter=ccn,ccp,cec`

<img src="screenshots/http-api-status-filtered.png?raw=true" />

## Setting values
Each value has to be set using an url query parameter (GET parameter). The value has be encoded as json. For example strings must start and end with quotation marks.

```
http://192.168.0.75/api/set?fna="my controller"
http://192.168.0.75/api/set?ccn=[null,null,null,null,null,null,"Fridge"]
http://192.168.0.75/api/set?dwo=null
http://192.168.0.75/api/set?dwo=3.14
http://192.168.0.75/api/set?bac=false&sdp=true
```

The HTTP response should contain a value for each api key in the json object, true for success, or a string error message.

```
{
  "bac": true,
  "sdp": true
}
```