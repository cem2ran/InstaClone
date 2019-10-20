open ReactNative;
open ReactNavigation;

include Stack.Make({
  type params = unit;
});

module HomeScreen = {
  [@react.component]
  let make = (~navigation) =>
    <Background centered=true>
      <Button
        title="Open Post"
        onPress={_ => navigation->Navigation.navigate("Post")}
      />
    </Background>;
};

module Ionicons = {
  [@bs.module "@expo/vector-icons"] [@react.component]
  external make: (~name: string, ~size: int, ~color: string) => React.element =
    "Ionicons";
};

[@react.component]
let make = () => {
  <Navigator>
    <Screen
      name="Profile"
      component=HomeScreen.make
      options={_props =>
        options(~headerStyle=Style.style(~backgroundColor="#fafafa", ()), ())
      }
    />
    <Screen
      name="Post"
      component=Post.make
      options={props =>
        options(
          ~headerLeft=
            _ =>
              <TouchableOpacity
                style=Style.(
                  style(
                    ~width=32.->dp,
                    ~height=32.->dp,
                    ~alignItems=`center,
                    ~justifyContent=`center,
                    (),
                  )
                )
                onPress={_ => props##navigation->Navigation.goBack()}>
                <Ionicons name="ios-arrow-back" size=24 color="grey" />
              </TouchableOpacity>,
          (),
        )
      }
    />
  </Navigator>;
};