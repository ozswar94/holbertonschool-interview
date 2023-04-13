#!/usr/bin/node

const request = require('request');

function allChar (charters, i) {
  if (i === charters.length) return;
  request(charters[i], function (err, resp, body) {
    if (err) console.log(err);
    else {
      console.log(JSON.parse(body).name);
      allChar(charters, ++i);
    }
  });
}

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}/`,
  function (err, resp, body) {
    if (err) console.log(err);
    else {
      const charters = JSON.parse(body).characters;
      allChar(charters, 0);
    }
  });
