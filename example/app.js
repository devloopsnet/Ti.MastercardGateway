
var Mastercard = require('net.devloops.mastercard.gateway');

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


let data = {
    'sessionId': SessionId,
    'apiVersion': ApiVersion,
    'token': '{token}',
};
MasterCard.updateSessionWithToken(data, res => {
    callback(res.success, SessionId, res);
});


MasterCard.start3DSecure({
    'html': html
});