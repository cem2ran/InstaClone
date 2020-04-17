open ReactNative;
open Styles;
let style = ViewStyle({alignItems: center});
let valueStyle = TextStyle({fontSize: 17., fontWeight: `_700});
let labelStyle = TextStyle({fontSize: 13., fontWeight: `_500, color: "#777"});

[@react.component]
let make = (~value, ~label) => {
  <View style>
    <Text style=valueStyle> value->React.string </Text>
    <Text style=labelStyle> label->React.string </Text>
  </View>;
};