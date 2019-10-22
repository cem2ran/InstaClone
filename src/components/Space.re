open ReactNative;

[@react.component]
let make = (~amount, ~vertical=false) =>
  <View
    style=Style.(
      vertical ? style(~height=amount->dp, ()) : style(~width=amount->dp, ())
    )
  />;

module Vertical = {
  let make = make;

  let makeProps = makeProps(~vertical=true);
};
