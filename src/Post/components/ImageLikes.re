open ReactNative;

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
        style=Style.(
          style(
            ~borderColor="white",
            ~borderWidth=1.5,
            ~marginLeft=(idx === 0 ? 0. : (-7.))->dp,
            ~zIndex=length - idx,
            (),
          )
        )
        size=20.
        source=Image.(
          Source.fromUriSource(
            uriSource(~uri="https://source.unsplash.com/featured", ()),
          )
        )
      />
    );
  };

  Style.(
    <Horizontal
      style={Style.style(
        ~paddingHorizontal=12.->dp,
        ~paddingVertical=5.->dp,
        (),
      )}>
      <Horizontal style={Style.style(~width=50.->dp, ())}>
        images->React.array
      </Horizontal>
      <T4>
        "Liked by "->React.string
        <T4_Bold value="baconbrix" />
        " and "->React.string
        <T4_Bold value={j|$likes others|j} />
      </T4>
    </Horizontal>
  );
};