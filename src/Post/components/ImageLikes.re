open ReactNative;
open Styles;
open Typography;

// NOTE: Mocked data for now as it doesn't seem like I can get
// likedBy data from unsplash

[@react.component]
let make = (~likes, ~likedByUsers=[|"a", "b", "c"|]) => {
  let length = likedByUsers->Belt.Array.length;
  let images = {
    likedByUsers->Belt.Array.mapWithIndex((idx, src) =>
      <CircularImage
        key=src
        style={
          ImageStyle({
            borderColor: "white",
            borderWidth: 1.5,
            marginLeft: (idx === 0 ? 0. : (-7.))->dp,
            zIndex: length - idx,
          })
        }
        size=20.
        source=Image.(
          Source.fromUriSource(
            uriSource(~uri="https://source.unsplash.com/featured", ()),
          )
        )
      />
    );
  };

  <Horizontal
    style={ViewStyle({paddingHorizontal: 12., paddingVertical: 5.})}>
    <Horizontal style={ViewStyle({width: 50.})}>
      images->React.array
    </Horizontal>
    <T4>
      "Liked by "->React.string
      <T4_Bold value="baconbrix" />
      " and "->React.string
      <T4_Bold value={j|$likes others|j} />
    </T4>
  </Horizontal>;
};