# Appcelerator Titanium Mobile Ti.MastercardGateway

[![gitTio](http://gitt.io/badge.svg)](http://gitt.io/component/net.devloops.mastercard.gateway) [![Abdullah Al-Faqeir](https://img.shields.io/badge/maintainer-Abdullah_Al_Faqeir-yellow.svg?style=flat-square)](https://github.com/abdullahfaqeir)

A proxy for Mastercard-Gateway iOS and Android sdk.


## Quick Start

### Get it [![gitTio](http://gitt.io/badge.png)](http://gitt.io/component/net.devloops.mastercard.gateway)
Download this repository and consult the [Alloy Documentation](http://docs.appcelerator.com/titanium/latest/#!/guide/Alloy_XML_Markup-section-35621528_AlloyXMLMarkup-ImportingWidgets) on how to install it, or simply use the [gitTio CLI](http://gitt.io/cli):

`$ gittio install net.devloops.mastercard.gateway`


## Example

The `example` directory contains code snippets on how to use the module.

## Building

Simply run `appc run -p [ios|android] --build-only` which will compile and package your module.

## Project Usage

Register your module with your application by editing `tiapp.xml` and adding your module.
Example:

```xml
<modules>
  <module version="1.0.0">net.devloops.mastercard.gateway</module>
</modules>
```

When you run your project, the compiler will combine your module along with its dependencies
and assets into the application.

## Example Usage

To use your module in code, you will need to require it.

### ES6+ (recommended)

```js
import Mastercard from 'net.devloops.mastercard.gateway';
Mastercard.updateSession('{sessionId}','{apiVersion}',{});
```

### ES5

```js
var Mastercard = require('net.devloops.mastercard.gateway');
Mastercard.updateSession('{sessionId}','{apiVersion}',{})
```

### Examples

- Update Session with Card
 ```javascript
 //Please reference mastercard api documentation for other params names.
  let data = {    
    'sourceOfFunds.provided.card.nameOnCard': card.name,
    'sourceOfFunds.provided.card.number': card.number,
    'sourceOfFunds.provided.card.securityCode': card.cvv,
    'sourceOfFunds.provided.card.expiry.month': card.expiry.month,
    'sourceOfFunds.provided.card.expiry.year': card.expiry.year,
  };
  MasterCard.updateSessionWithCard(SessionId, ApiVersion, data res => {
    callback(res.success, SessionId, res);
  });
```

- Update Session with Card
 ```javascript
  let data = {
    'sessionId': SessionId,
    'apiVersion': ApiVersion,
    'nameOnCard': card.name,
    'number': card.number,
    'securityCode': card.cvv,
    'expiryMonth': card.expiry.month,
    'expiryYear': card.expiry.year,
  };
  MasterCard.updateSessionWithCard(data, res => {
    callback(res.success, SessionId, res);
  });
```

- Update Session with Token
 ```javascript
  let data = {
    'sessionId': SessionId,
    'apiVersion': ApiVersion,
    'token': '{token}',    
  };
  MasterCard.updateSessionWithToken(data, res => {
    callback(res.success, SessionId, res);
  });
```

- Start 3DSecure process
 ```javascript
 MasterCard.start3DSecure({
    'html': '{html string}'
  });
 ```


## Events

| Name  | Usage |
| ---------  | ----------- |
| threeds_success     | When 3DSecure process is successful. |
| threeds_error       | When 3DSecure process fails. |


## Methods

| Function   | Parameters | Usage |
| ---------- | ---------- | ----- |
| updateSession           | `string`, `string`, `object`, `callack`   | To update session the same way the native sdk works |
| updateSessionWithCard   | `object`, `callback`   | To update session with the card details in a simple way |
| updateSessionWithToken  | `object`, `callback`      | To update session with a card token in a simple way  |
| start3DSecure           | `object`  | To start 3DSecure process |



## Changelog
* 1.0: Initial version


## License

<pre>
Copyright 2020 Devloops LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
</pre>

