open ReactNative;
open Typography;
open Styles;

[@react.component]
let make = (~username, ~description) =>
  <View style={ViewStyle({paddingHorizontal: 12.->dp})}>
    <T4>
      <T4_Bold value={j|$username |j} />
      Option.(description or "")->React.string
    </T4>
  </View>;