open ReactNative;
open Style;
[@react.component]
let make = (~size=24) =>
  <View
    style={Style.style(
      ~justifyContent=`center,
      ~width=size->float_of_int->dp,
      (),
    )}>
    <IonIcons name="ios-more" size color="grey" />
  </View>;
