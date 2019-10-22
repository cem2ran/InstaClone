open ReactNative;

let style = Style.(style(~alignItems=`center, ()));
let valueStyle = Style.textStyle(~fontSize=17., ~fontWeight=`_700, ());
let labelStyle =
  Style.textStyle(~fontSize=13., ~fontWeight=`_500, ~color="#777", ());

[@react.component]
let make = (~value, ~label) => {
  <View style>
    <Text style=valueStyle> value->React.string </Text>
    <Text style=labelStyle> label->React.string </Text>
  </View>;
};