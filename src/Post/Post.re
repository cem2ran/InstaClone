open ReactNative;
[@react.component]
let make = (~navigation) =>
  <Background centered=true>
    <Text> {j|Post content|j}->React.string </Text>
  </Background>;