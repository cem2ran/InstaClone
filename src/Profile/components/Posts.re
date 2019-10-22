open ReactNative;

module GetPhotosGQL = [%graphql
  {|
query GetPhotos($count: Int, $curated: Boolean, $page: Int, $orderBy: String){
  photos(count: $count, curated: $curated, page: $page, orderBy: $orderBy ){
    id
    urls {
      small
    }
  }
}
|}
];

module GetPhotosQuery = ReasonApolloHooks.Query.Make(GetPhotosGQL);

[@react.component]
let make = (~id="seemoris", ~navigateToPost) => {
  let (_simple, full) =
    GetPhotosQuery.use(
      ~variables=GetPhotosGQL.make(~count=15, ())##variables,
      ~notifyOnNetworkStatusChange=true,
      (),
    );

  let data =
    switch (full) {
    | {data: Some(data)} => data##photos
    | {loading: true, data: None}
    | _ => [||]
    };
  <ScrollView>
    <ProfileInfo id />
    <PhotoGrid data loading={full.loading} onPress=navigateToPost />
  </ScrollView>;
};

[@genType]
let default = make;

type id = string;

type image = [ | `Image(string)];
type media = [ image | `Gallery(list(image)) | `Video(string)];

type created_at = timestamp
and timestamp = int;

type posts = array(post)
and post = {
  id,
  description: string,
  created_at,
  likes,
  comments,
  media,
  author: user,
}
and user = {
  id,
  username: string,
  posts,
  follows,
  followers,
}
and likes = list(like)
and like = {
  id,
  user,
  timestamp,
}
and comments = list(comment)
and comment = {
  id,
  content: string,
  timestamp,
  user,
}
and follows = list(follow)
and follow = {
  id,
  timestamp,
  user,
}
and followers = follows;
