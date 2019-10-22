open ReactNative;
open Typography;

[@react.component]
let make = (~username, ~description) =>
  <View style=Style.(style(~paddingHorizontal=12.->dp, ()))>
    <T4>
      <T4_Bold value={j|$username |j} />
      Option.(description or "")->React.string
    </T4>
  </View>;