open ReactNative;
open PostData;
open Styles;

let description = {j|🏠 Chicago
🚀 @draftbit co-founder
🌱 @petersplantss
🧘🏻‍♂️ I live for a living
💯 Y Combinator W18
🙌 Building a co & one day at a time & fkin lovin’ it 👌🏻|j};

[@react.component]
let make = (~id) => {
  let (_simple, full) =
    GetPhotoByIdQuery.use(
      ~variables=GetPhotoByIdGQL.make(~id, ())##variables,
      ~notifyOnNetworkStatusChange=true,
      (),
    );

  switch (full) {
  | {data: Some(data)} =>
    let user = data##getPhotoById##user;
    <View
      style={
        ViewStyle({
          justifyContent: spaceBetween,
          paddingHorizontal: 12.,
          paddingVertical: 12.,
        })
      }>
      <Horizontal>
        <TouchableWithoutFeedback
          onPress={_ => Js.log("Click Profile Image")}>
          <CircularImage
            size=80.
            source=Image.(
              Source.fromUriSource(
                uriSource(~uri=user##profile_image##small, ()),
              )
            )
          />
        </TouchableWithoutFeedback>
        <Space amount=10. />
        <View style=Style.(style(~flex=1., ()))>
          <Stats
            posts=user##total_photos
            followers=user##followers_count
            following=user##following_count
          />
          <Space.Vertical amount=7. />
          <EditButton />
        </View>
      </Horizontal>
      <Space.Vertical amount=12. />
      <View>
        <Typography.Name value=user##name />
        Option.(user##bio && (value => <Typography.Description value />))
        <Space.Vertical amount=3. />
        Option.(user##portfolio_url && (value => <Typography.Link value />))
      </View>
    </View>;

  | _ => <ActivityIndicator />
  };
};