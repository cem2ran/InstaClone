open ReactNative;

[@react.component]
let make = (~posts, ~followers, ~following) =>
  <Horizontal style=Style.(style(~justifyContent=`spaceEvenly, ()))>
    <StatBox value={posts->string_of_int} label="posts" />
    <StatBox value={followers->string_of_int} label="followers" />
    <StatBox value={following->string_of_int} label="following" />
  </Horizontal>;
