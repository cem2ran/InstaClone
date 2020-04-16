open ReactNative;
open ReactNavigation;
open Styles;

include Stack.Make({
  type params = string;
});

module HomeScreen = {
  [@react.component]
  let make = (~navigation: Core.navigation, ~route) =>
    <Background centered=true>
      <Posts
        navigateToPost={id =>
          navigation->Navigation.navigateWithParams("Post", id)
        }
      />
    </Background>;
};

[@react.component]
let make = () => {
  <Navigator>
    <Screen
      name="Profile"
      component=HomeScreen.make
      options={_props =>
        options(~headerStyle=ViewStyle({backgroundColor: "#fafafa"}), ())
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
                style={
                  ViewStyle({
                    width: 32.->dp,
                    height: 32.->dp,
                    alignItems: `center,
                    justifyContent: `center,
                  })
                }
                onPress={_ => props##navigation->Navigation.goBack()}>
                <IonIcons name="ios-arrow-back" size=24 color="grey" />
              </TouchableOpacity>,
          (),
        )
      }
    />
  </Navigator>;
};

[@genType]
let default = make;