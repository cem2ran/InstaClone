open ReactNative;
include PostRoute;
open PostData;

let window = Dimensions.get(`window);

let width = window.width;

[@react.component]
let make = (~navigation, ~route: Navigation.route) => {
  let id = route##params->Belt.Option.getExn;

  let (_simple, full) =
    GetPhotoByIdQuery.use(
      ~variables=GetPhotoByIdGQL.make(~id, ())##variables,
      ~notifyOnNetworkStatusChange=true,
      (),
    );

  <Background>
    {switch (full) {
     | {data: Some(data)} =>
       <ScrollView>
         <ImageHeader
           username=data##getPhotoById##user##username
           location=data##getPhotoById##location
           image=data##getPhotoById##user##profile_image##small
         />
         <Image
           source=Image.(
             Source.fromUriSource(
               uriSource(
                 ~uri=data##getPhotoById##urls##regular,
                 ~width,
                 ~height=width,
                 (),
               ),
             )
           )
         />
         <ImageActions
           liked={
             data##getPhotoById##liked_by_user
             ->Belt.Option.getWithDefault(false)
           }
         />
         <ImageLikes likes=data##getPhotoById##likes />
         <ImageDescription
           username=data##getPhotoById##user##username
           description=data##getPhotoById##description
         />
       </ScrollView>
     | {loading: true, data: None} =>
       <Text> {j|Loading|j}->React.string </Text>
     | _ => <Text> {j|Error|j}->React.string </Text>
     }}
  </Background>;
};

[@genType]
let default = make;